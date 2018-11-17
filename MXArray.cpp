/******************************************************************************* 
** Magnus MAGNUX Cpp source code 
** (c) Copyright 2011-2018 Magnus siiftun1857 Frankline 
** This creation is licensed under Apache License Version 2.0 
** For more information, see LICENSE and README.MD 
**  
** Filename: siiftun1857/magnux-core/MXArray.cpp 
** Author: Magnus siiftun1857 Frankline 
** Date: 2018-11-18 09:43:40 
** 
*/
#include "MXArray.h"
namespace magnux
{
#define nullptr 0
	
	// 指定下一跳的构造函数 | Constructor with nextptr 
	template <typename datatype>
	MXArray<datatype>::MXArray(datatype initdata,MXArray*manualnextptr)
	{
		nextptr = manualnextptr;
		data = initdata;
	}
	
	// 获取指定元素的指针 | Last element ptr 
	template <typename datatype>
	MXArray<datatype>* MXArray<datatype>::getPtrByIdent(int byident) const
	{
		if(byident < 0)
		{
			int target = getLength()+byident;
			if(target < 0)
				return  nullptr;
			return getPtrByIdent(target);
		}
		if(byident == 0)
			return this;
		if(byident > 0)
		{
			if(nextptr==nullptr)
				return nullptr;
			return nextptr->getTargetByIdent(byident - 1);
		}
	}
	// 获取末尾元素指针 | Get last element ptr 
	template <typename datatype>
	MXArray<datatype>* MXArray<datatype>::getFinalPtr() const
	{
		if(nextptr == nullptr)
			return this;
		return nextptr->getFinalPtr();
	}
	
	// 析构函数 | Destructor
	template <typename datatype>
	MXArray<datatype>::~MXArray()
	{
		delete nextptr;//trigger next destructor
	}
	// 标准构造函数 | Standard constructor 
	template <typename datatype>
	MXArray<datatype>::MXArray()
	{
		nextptr = nullptr;
	}
	// 带数据的构造函数 | Constructor with init data
	template <typename datatype> 
	MXArray<datatype>::MXArray(datatype initdata)
	{
		nextptr = nullptr;
		data = initdata;
	}
	// 获取深度 | Get length
	template <typename datatype>
	unsigned int MXArray<datatype>::getLength() const
	{
		if(nextptr == nullptr)
		{
			return 1;
		}
		return nextptr->getLength()-1;
	}
	// 获取指定元素的数据引用 | Get reference by element ident 
	template <typename datatype>
	datatype& MXArray<datatype>::getReferByIdent(int byident) const
	{
		try{
			return getPtrByIdent(byident)->data;
		}
		catch(...)//TODO: magnux exception 
		{
			throw;
		}
	}
	// 追加末尾 | Append 
	template <typename datatype>
	datatype& MXArray<datatype>::append(datatype&initdata)
	{
		return (getFinalPtr()->nextptr = new MXArray(initdata))->data;
	}
	// 追加特定元素的末尾 | Append by ident 
	template <typename datatype>
	datatype& MXArray<datatype>::add(datatype&initdata,int byident)
	{
        try{
			MXArray*target = getPtrByIdent(byident);
			if(target==nullptr)
			{
				throw;
			}
			return (target->nextptr = new MXArray(initdata,target))->data;
		}
		catch(...)//TODO: magnux exception 
		{
			throw;
		}
	}
	// 出栈末尾 | Pop
	template <typename datatype>
	datatype MXArray<datatype>::popend()
    {
		MXArray*finalptr = getFinalPtr();
		datatype& popdata = finalptr->data;
		delete finalptr;
		getFinalPtr()->nextptr = nullptr;
		return popdata;
	}
	// 摧毁特定元素 | Destruct element by ident 
	template <typename datatype>
	datatype MXArray<datatype>::popByIdent(int byident)
	{
		try{
            if(byident==0)
            {
                throw;
            }
			MXArray*target = getPtrByIdent(byident);
			if(target==nullptr)
			{
				throw;
			}
			datatype& popdata = target->data;
			MXArray*popnextptr = target->nextptr;
			target->nextptr=nullptr;
			delete target;
            getPtrByIdent(byident-1)->nextptr = popnextptr;//TODO:bug detected
			return popdata;
		}
		catch(...)//TODO: magnux exception 
		{
			throw;
		}
	}
}//end namespace magnux 

/* eof MXArray.cpp */
