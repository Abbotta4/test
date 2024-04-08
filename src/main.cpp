#include <iostream>
#include <sqlpp11/postgresql/connection.h>
#include <sqlpp11/select.h>
#include "users.h"

sqlpp::postgresql::connection getDB() {
    auto config = std::make_shared<sqlpp::postgresql::connection_config>();
    config->host = "localhost";
    config->user = "postgres";
    config->password = "";
    config->dbname = "postgres";
    sqlpp::postgresql::connection db(config);
    return db;
}

std::string queryUsers(int uid) {
    users::PublicTest users;
    auto db = getDB();
    auto res = db(select(users.joined)
		  .from(users)
		  .where(users.uid == 1));
    if (!res.empty()) {
	std::chrono::time_point<std::chrono::system_clock> joined = res.front().joined;
	return joined.time_since_epoch();
    }

    return "";
}

int main() {
    std::cout << queryUsers(1) << std::endl;
    return 0;
}
