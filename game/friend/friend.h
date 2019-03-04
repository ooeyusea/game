#ifndef __FRIEND_H__
#define __FRIEND_H__
#include "hnet.h"
#include "nodedefine.h"
#include "conf.h"
#include "spin_mutex.h"
#include "rpcdefine.h"

class Friend : public Conf, public Envir {
public:
	Friend();
	~Friend() {}

private:
	bool Initialize();
	bool LoadDB();

};

#endif //__FRIEND_H__
