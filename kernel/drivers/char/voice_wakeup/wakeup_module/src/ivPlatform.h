/*----------------------------------------------+
 |
 |	ivPlatform.h - Platform Config
 |
 |		Copyright (c) 1999-2013, iFLYTEK Ltd.
 |		All rights reserved.
 |
 +----------------------------------------------*/


/*
 *	TODO: 在这里包含目标平台程序需要的公共头文件
 */


#ifdef _WIN32
#include <stdio.h>
#include <crtdbg.h>
#endif


/*
 *	TODO: 根据目标平台特性修改下面的配置选项
 */

#define IV_PTR_GRID				4			/* 最大指针对齐值 */
#define IV_UNIT_BITS            8			/* 内存基本单元位数 */
//#define IV_BIG_ENDIAN			0			/* 是否是 Big-Endian 字节序 */

#define IV_CSI                  (0)			/* 科胜讯16位平台 */

#define IV_PTR_PREFIX						/* 指针修饰关键字(典型取值有 near | far, 可以为空) */
#define IV_CONST				const		/* 常量关键字(可以为空) */
#define IV_EXTERN				extern		/* 外部关键字 */
#define IV_STATIC				static		/* 静态函数关键字(可以为空) */
#define IV_INLINE				//__inline	/* 内联关键字(典型取值有 inline, 可以为空) */
#define IV_CALL_STANDARD		//__stdcall	/* 普通函数修饰关键字(典型取值有 stdcall | fastcall | pascal, 可以为空) */

#define IV_CALL_REENTRANT					/* 递归函数修饰关键字(典型取值有 stdcall | reentrant, 可以为空) */
#define IV_CALL_VAR_ARG						/* 变参函数修饰关键字(典型取值有 cdecl, 可以为空) */

#if IV_CSI  /* 打开为科胜讯平台配置. 资源也需要重新打包才匹配!!!! */
#define IV_TYPE_INT8			short		/* 8位数据类型 */
#else
#define IV_TYPE_INT8			char		/* 8位数据类型 */
#endif

#define IV_TYPE_INT16			short		/* 16位数据类型 */
#define IV_TYPE_INT24			int			/* 24位数据类型 */
#define IV_TYPE_INT32			long		/* 32位数据类型 */

#define IV_SIZEOF(exp)			(sizeof(exp))

#define IV_TYPE_ADDRESS			unsigned long		/* 地址数据类型 */
#define IV_TYPE_SIZE			unsigned long		/* 大小数据类型 */

#define IV_VOLATILE				volatile

#define IV_ANSI_MEMORY			0			/* 是否使用 ANSI 内存操作库 */
#define	IV_ANSI_STRING			0			/* 是否使用 ANSI 字符串操作库 */

#if defined __GNUC__
#define IV_GNUC_COMPILER        1
#endif

#define IV_ARM_COMPILER			0

#if defined _MSC_VER
#define IV_WIN32_COMPILER       1
#endif

#ifdef _WIN32
#define IV_ASSERT(exp)			_ASSERT(exp)/* 断言操作(可以为空) */
#else
#define IV_ASSERT(exp)			/* 断言操作(可以为空) */
#endif

#define IV_YIELD				/* 空闲操作(在协作式调度系统中应定义为任务切换调用, 可以为空) */

/* 根据平台编译选项决定是否支持调试 */
#if defined(DEBUG) || defined(_DEBUG)
	#define IV_DEBUG			1			/* 是否支持调试 */
#else
	#define IV_DEBUG			0			/* 是否支持调试 */
#endif

/* 根据平台编译选项决定是否以 Unicode 方式构建 */
#if defined(UNICODE) || defined(_UNICODE)
	#define IV_UNICODE			1			/* 是否以 Unicode 方式构建 */
#else
	#define IV_UNICODE			0			/* 是否以 Unicode 方式构建 */
#endif
