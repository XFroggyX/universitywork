#include "Session.h"

#include <utility>

Session::Session(Plan plan) {
    session = std::move(plan);
}
