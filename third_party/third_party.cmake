# glog
add_library(third_party_glog SHARED IMPORTED)
set(GLOG_ROOT_DIR "${PROJECT_SOURCE_DIR}/third_party/glog")
set_target_properties(third_party_glog PROPERTIES
  IMPORTED_LOCATION "${GLOG_ROOT_DIR}/lib/libglog.so"
  INTERFACE_INCLUDE_DIRECTORIES "${GLOG_ROOT_DIR}/include"
)

# gflags
add_library(third_party_gflags STATIC IMPORTED)
set(GFLAGS_ROOT_DIR "${PROJECT_SOURCE_DIR}/third_party/gflags")
set_target_properties(third_party_gflags PROPERTIES
  IMPORTED_LOCATION "${GFLAGS_ROOT_DIR}/lib/libgflags.a"
  INTERFACE_INCLUDE_DIRECTORIES "${GFLAGS_ROOT_DIR}/include"
)

# jsoncpp
add_library(third_party_jsoncpp SHARED IMPORTED)
set(JSONCPP_ROOT_DIR "${PROJECT_SOURCE_DIR}/third_party/jsoncpp")
set_target_properties(third_party_jsoncpp PROPERTIES
  IMPORTED_LOCATION "${JSONCPP_ROOT_DIR}/lib/libjsoncpp.so"
  INTERFACE_INCLUDE_DIRECTORIES "${JSONCPP_ROOT_DIR}/include"
)