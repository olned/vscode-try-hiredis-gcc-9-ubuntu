add_executable(redis_ping ping.cpp)
target_link_libraries(redis_ping hiredis)