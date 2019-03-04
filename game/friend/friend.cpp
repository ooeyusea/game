#include "friend.h"
#include "initializor.h"
#include "XmlReader.h"
#include "servernode.h"
#include <thread>
#include "mysqlmgr.h"
#include "object_holder.h"
#include "dbdefine.h"

#define DEFAULT_POOL_SIZE (1024 * 1024)
#define DEFAULT_BATCH (8 * 1024)

Friend g_friend;

Friend::Friend() {
	InitializorMgr::Instance().AddStep("Friend#Init", [this]() {
		return Initialize();
	});

	InitializorMgr::Instance().AddStep("Friend#LoadDB", [this]() {
		return LoadDB();
	});
}

bool Friend::Initialize() {
	return true;
}

bool Friend::LoadDB() {
	try {
		olib::XmlReader conf;
		if (!conf.LoadXml(_conf.c_str())) {
			return false;
		}

		const char * dsn = conf.Root()["mysql"][0]["friend_data"][0].GetAttributeString("dsn");
		auto * executor = MysqlMgr::Instance().Open(dsn);
		if (!executor) {
			return false;
		}

		Holder<MysqlExecutor, db_def::FRIEND> holder(executor);
	}
	catch (std::exception& e) {
		hn_error("Load Cache Config : {}", e.what());
		return false;
	}

	return true;
}
