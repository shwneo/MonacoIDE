#ifndef __NX_FERRANDO_H__
#define __NX_FERRANDO_H__

#include "nxIFerrando.h"
#include "mozilla/Attributes.h"

#define NX_FERRANDO_CONTRACTID "@general.org/interface/nxIFerrando;1"
#define NX_FERRANDO_CID	NXIFERRANDO_IID

/* Header file */
class nxFerrando : public nxIFerrando
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NXIFERRANDO

  nxFerrando();

private:
  ~nxFerrando();

protected:
  /* additional members */
};

#endif