/******************************************************************************* 
** Magnus MAGNUX Cpp source code 
** (c) Copyright 2011-2018 Magnus siiftun1857 Frankline 
** This creation is licensed under Apache License Version 2.0 
** For more information, see LICENSE and README.MD 
**  
** Filename: siiftun1857/magnux-core/MXAlgorithm.cpp 
** Author: Magnus siiftun1857 Frankline 
** Date: 2018-11-18 11:38:12 
** 
*/
#include "MXAlgorithm.h"
namespace magnux
{

void quickSort(bool (*cmpFun)(unsigned int,unsigned int),void(*setDataFun)(unsigned int,unsigned int),unsigned int leftEdge, unsigned int rightEdge)
{
	//快速排序之前先判断一下当前待排序数组元素个数是不是大于1 否则就没有必要排序
	if (leftEdge >= rightEdge)
	{
		//直接退出排序代码  没有必要进行排序了
		return; 
	}

	//开始进行快排算法
	//首先我们先保存left索引对应的数据  当前数据作为切割数组的轴
    unsigned int piovt = leftEdge;

	//定义临时变量保存数组2端的索引
    unsigned int leftIndex = leftEdge;
    unsigned int rightIndex = rightEdge;

    while ((*cmpFun)(leftIndex,rightIndex))
	{
		//现在我们通过循环从右边开始搜索一个比轴值小的数据
		while ((*cmpFun)(leftIndex,rightIndex))
		{
			//如果右边的数大于当前的参数轴值
			if ((*cmpFun)(rightIndex,piovt))
			{
				//右端索引指示器左移
				rightIndex--;
			}
			else
			{
				//说明我们右端出现比轴值更大的数据
				//这个时候我们就可以把这个更大的数据填充到索引轴索引对应的地方
				(*setDataFun)(leftIndex,rightIndex);
				leftIndex++;
				//我们需要跳出循环了当前工作完毕
				break;
			}
		}

		//从左边开始搜索一个比轴值更大的数填写上次留下的坑
		while ((*cmpFun)(leftIndex,rightIndex))
		{
			//如果左边的数据小于轴值 我们索引指示器就往右走
			if ((*cmpFun)(leftIndex,piovt))
			{
				leftIndex++;
			}
			else
			{
				//说明我们在左端找到了比轴值更大的数据
				(*setDataFun)(rightIndex,leftIndex);
				rightIndex--;
				break;
			}
		}
	}

	(*setDataFun)(leftIndex,piovt);

	quickSort(cmpFun, setDataFun, leftEdge, leftIndex - 1);
	quickSort(cmpFun, setDataFun, rightIndex + 1, rightEdge);
}

}//end namespace magnux 

/* eof MXAlgorithm.cpp */
