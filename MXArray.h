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

// Magnux�������� | Magnux Chain Array
template <typename datatype>
class MXArray
{
private:

	// ��һ����ַ | Next element ptr 
	MXArray*nextptr;
	// ��Ҫ�������� | Primary data 
	datatype data;
	
	// ָ����һ���Ĺ��캯�� | Constructor with nextptr 
	MXArray(datatype initdata,MXArray*manualnextptr);
	
	// ��ȡָ��Ԫ�ص�ָ�� | Last element ptr 
	MXArray*getPtrByIdent(int byident) const;
	// ��ȡĩβԪ��ָ�� | Get last element ptr 
	MXArray*getFinalPtr() const;
public:
	
	// �������� | Destructor
	~MXArray();
	// ��׼���캯�� | Standard constructor 
	MXArray();
	// �����ݵĹ��캯�� | Constructor with init data 
	MXArray(datatype initdata);
	// ��ȡ��� | Get length
	size_t getLength() const;
	// ��ȡָ��Ԫ�ص��������� | Get reference by element ident 
	datatype& getReferByIdent(size_t byident) const;
	// ׷��ĩβ | Append 
	datatype& append(datatype&initdata);
	// ׷���ض�Ԫ�ص�ĩβ | Append by ident 
	datatype& add(datatype&initdata,size_t byident);
	// ׷���ض�Ԫ�ص�ĩβ | Append by ident 
	datatype& add(datatype&initdata,size_t byident);
	// ��ջĩβ | Pop
	datatype popend();
	// �ݻ��ض�Ԫ�� | Destruct element by ident 
	datatype popByIdent(size_t byident);
}
}//end namespace array 
}//end namespace magnux 

#endif // !ifdef _MXARRAY_H

/* eof MXArray.h */

