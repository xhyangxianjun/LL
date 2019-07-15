#ifndef TYPEDEFINES_H
#define TYPEDEFINES_H
#include <intsafe.h>
#include <limits.h>

typedef unsigned int   ReqId;
typedef  int                  ErrorCode;

#define INVALID_REQID   -1

//---------------------------------
typedef int             INT32;
typedef long long  INT64;

//limits-------------------------
#define   MAX_INT32           INT_MAX
#define   MAX_UINT32        UINT_MAX
#define   MAX_INT64           LONGLONG_MAX
#define   MAX_UINT64         ULONG64_MAX
#define   MAX_DOUBLE	    DBL_MAX
#define   MAX_FLOAT	        FLT_MAX


#endif // TYPEDEFINES_H
