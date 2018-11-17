/******************************************************************************* 
** Magnus MAGNUX Cpp head code 
** (c) Copyright 2011-2018 Magnus siiftun1857 Frankline 
** This creation is licensed under Apache License Version 2.0 
** For more information, see LICENSE and README.MD 
**  
** Filename: siiftun1857/magnux-core/MXArray.h 
** Author: Magnus siiftun1857 Frankline 
** Date: 2018-11-18 09:43:51 
** 
*/
#ifndef _MXARRAY_H_
#define __MXARRAY_H

//#include "MAGNUX_CORE.H"

namespace magnux
{
namespace array
{

// Magnux链表数组 | Magnux Chain Array
template <typename datatype>
class MXArray
{
private:

	// 下一跳地址 | Next element ptr 
	MXArray*nextptr;
	// 主要数据区域 | Primary data 
	datatype data;
	
	// 指定下一跳的构造函数 | Constructor with nextptr 
	MXArray(datatype initdata,MXArray*manualnextptr);
	
	// 获取指定元素的指针 | Last element ptr 
	MXArray*getPtrByIdent(int byident) const;
	// 获取末尾元素指针 | Get last element ptr 
	MXArray*getFinalPtr() const;
public:
	
	// 析构函数 | Destructor
	~MXArray();
	// 标准构造函数 | Standard constructor 
	MXArray();
	// 带数据的构造函数 | Constructor with init data 
	MXArray(datatype initdata);
	// 获取深度 | Get length
	size_t getLength() const;
	// 获取指定元素的数据引用 | Get reference by element ident 
	datatype& getReferByIdent(size_t byident) const;
	// 追加末尾 | Append 
	datatype& append(datatype&initdata);
	// 追加特定元素的末尾 | Append by ident 
	datatype& add(datatype&initdata,size_t byident);
	// 追加特定元素的末尾 | Append by ident 
	datatype& add(datatype&initdata,size_t byident);
	// 出栈末尾 | Pop
	datatype popend();
	// 摧毁特定元素 | Destruct element by ident 
	datatype popByIdent(size_t byident);
}
}//end namespace array 
}//end namespace magnux 

#endif // !ifdef _MXARRAY_H

/* eof MXArray.h */

