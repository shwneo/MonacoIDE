#ifndef __NX_FOREGINCALLER_H__
#define __NX_FOREGINCALLER_H__

#include "nxIForeginCaller.h"
#include "mozilla/Attributes.h"

#define NX_FOREGINCALLER_CONTRACTID "@general.org/interface/nxIForeginCaller;1"
#define NX_FOREGINCALLER_CID NXIFOREGINCALLER_IID

/* Header file */
class nxForeginCaller : public nxIForeginCaller
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NXIFOREGINCALLER

  nxForeginCaller();

private:
  ~nxForeginCaller();

protected:
  /* additional members */
};


#endif /* __NX_FOREGINCALLER_H__ */