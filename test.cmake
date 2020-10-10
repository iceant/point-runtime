add_executable(pr_types.t pr_types.t.c)

add_executable(pr_memory.t pr_memory.t.c)
target_link_libraries(pr_memory.t point_runtime)