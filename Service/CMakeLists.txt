# Build a service.
add_library(MySvc_service SHARED MySvc_service.cc)
target_link_libraries(MySvc_service ${service_lib_list})
