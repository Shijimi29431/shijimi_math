
set(target tmp-example)
set(sources	tmp.cpp)
add_executable(${target} ${sources})
target_link_libraries(${target} ${Boost_LIBRARIES})

set(target auto_diff-example)
set(sources	auto_diff.cpp)
add_executable(${target} ${sources})
target_link_libraries(${target} ${Boost_LIBRARIES})