/******************************************************************************* 
** Magnus MAGNUX Cpp head code 
** (c) Copyright 2011-2018 Magnus siiftun1857 Frankline 
** This creation is licensed under Apache License Version 2.0 
** For more information, see LICENSE and README.MD 
**  
** Filename: siiftun1857/magnux-core/MXAlgorithm.h 
** Author: Magnus siiftun1857 Frankline 
** Date: 2018-11-18 12:54:47 
** 
*/
#ifndef _MXALGORITHM_H_
#define __MXALGORITHM_H


#if _MSC_VER > 1000 
#pragma once
#endif // _MSC_VER > 1000

//#include "MAGNUX_CORE.H"

namespace magnux
{

void quickSort(bool (*cmpFun)(unsigned int,unsigned int),void(*setDataFun)(unsigned int,unsigned int),int leftEdge, int rightEdge);

}//end namespace magnux 

#endif // !ifdef _MXALGORITHM_H

/* eof MXAlgorithm.h */
