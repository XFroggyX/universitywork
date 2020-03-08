#include "Session.h"

#include <utility>

Session::Session(Plan plan) {
    session = std::move(plan);
}

Plan &Session::get_session() {
    return session;
}
