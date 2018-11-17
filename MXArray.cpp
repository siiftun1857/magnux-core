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
#include <MXArray.h>
namespace magnux
{
namespace array
{
	// 获取指定元素的指针 | Last element ptr 
	MXArray*MXArray::getPtrByIdent(int byident) const
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
	MXArray*MXArray::getFinalPtr() const
	{
		if(nextptr == nullptr)
			return this;
		return nextptr->getFinalPtr();
	}
	
	// 析构函数 | Destructor
	~MXArray::MXArray()
	{
		delete nextptr;//trigger next destructor
	}
	// 标准构造函数 | Standard constructor 
	MXArray::MXArray()
	{
		nextptr = nullptr;
	}
	// 带数据的构造函数 | Constructor with init data 
	MXArray::MXArray(datatype initdata)
	{
		nextptr = nullptr;
		data = initdata;
	}
	// 获取深度 | Get length
	size_t MXArray::getLength() const
	{
		if(nextptr == nullptr)
		{
			return 1;
		}
		return nextptr->getLength()-1;
	}
	// 获取指定元素的数据引用 | Get reference by element ident 
	datatype& MXArray::getReferByIdent(int byident) const
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
	datatype& MXArray::append(datatype&initdata)
	{
		return (getFinalPtr()->nextptr = new MXArray(initdata))->data;
	}
	// 追加特定元素的末尾 | Append by ident 
	datatype& MXArray::add(datatype&initdata,int byident)
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
	// 追加特定元素的末尾 | Append by ident 
	datatype& MXArray::add(datatype&initdata,int byident)
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
	datatype MXArray::popend()
	{
		MXArray*finalptr = getFinalPtr();
		datatype& popdata = finalptr->data;
		delete finalptr;
		getFinalPtr()->nextptr = nullptr;
		return popdata;
	}
	// 摧毁特定元素 | Destruct element by ident 
	datatype MXArray::popByIdent(int byident)
	{
		try{
			MXArray*target = getPtrByIdent(byident);
			if(target==nullptr)
			{
				throw;
			}
			datatype& popdata = target->data;
			MXArray*popnextptr = target->nextptr;
			target->nextptr=nullptr;
			delete target;
			getPtrByIdent(byident-1)->nextptr = popnextptr;
			return popdata;
		}
		catch(...)//TODO: magnux exception 
		{
			throw;
		}
	}
}//end namespace array 
}//end namespace magnux 

/* eof MXArray.cpp */
