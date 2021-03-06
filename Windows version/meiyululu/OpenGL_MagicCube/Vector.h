//========================================================
/**
*  @file      Vector.h
*
*  文件描述:  向量类  
*  适用平台： Windows98/2000/NT/XP
*  
*
*/     
//========================================================

#ifndef __VECTOR_H__
#define __VECTOR_H__

#include "stdafx.h"

#define  EPRECISION  0.001

//PI的宏定义
#define M_PI        3.141592653589
#define M_2PI       6.283185307178


/** 向量类 */
class Vector3
{
public:
	/** 构造函数 */
	Vector3()  { x = 0.0; y = 0.0; z = 0.0; }
	Vector3( float xx, float yy, float zz)
	{
		x = xx;
		y = yy;
		z = zz;
	}
	Vector3(const Vector3& vec)
	{
		x = vec.x;
		y = vec.y;
		z = vec.z;
	}
    
	/** 成员函数 */
	inline float length();                       /**< 计算向量长度 */
	Vector3 normalize();                         /**< 单位化向量 */
	float dotProduct(const Vector3& v);          /**< 计算点积 */
	Vector3 crossProduct(const Vector3& v);      /**< 计算叉积 */

	/** 重载操作符 */
	Vector3 operator + (const Vector3& v);
	Vector3 operator - (const Vector3& v);
	Vector3 operator * (float scale);
	Vector3 operator / (float scale);
	Vector3 operator - ();
	
public:
	  float x,y,z;

};

/** 二维向量类 */
class Vector2
{
public:
	/** 构造函数 */
	Vector2(float xx = 0.0,float yy = 0.0) { x = xx; y = yy;  }
	Vector2(const Vector2& v)
	{
		x = v.x;
		y = v.y;
	}

public:
	float x,y;
};

Vector3 *Vector3Transform(Vector3 * pOut, Vector3 * pIn, float *M);
bool IntersectTri(Vector3 *p0, Vector3 *p1, Vector3 *p2, Vector3 *RayPos, Vector3 *RayDir, float *U, float *V, float *Dist);

#endif //__VECTOR_H__