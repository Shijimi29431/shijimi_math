
set(target tmp-example)

set(sources
	tmp.cpp
)

add_executable(${target} ${sources})

target_link_libraries(${target} ${Boost_LIBRARIES})

