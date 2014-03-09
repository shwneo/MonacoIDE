#ifndef __NX_GLORY_H__
#define __NX_GLORY_H__
#include "nxIGlory.h"
#include "mozilla/Attributes.h"
/* Header file */
class nxGlory : public nxIGlory
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NXIGLORY

  nxGlory();

private:
  ~nxGlory();

protected:
  /* additional members */
	void * pnxGloryPrivData;
};

#define NX_GLORY_CID	NXIGLORY_IID
#define NX_GLORY_CONTRACTID "@monaco-nx.com/interfaces/nxGlory;1"

#endif