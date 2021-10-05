# glog
add_library(third_party_glog SHARED IMPORTED)
set(GLOG_ROOT_DIR "${PROJECT_SOURCE_DIR}/third_party/glog")
set_target_properties(third_party_glog PROPERTIES
  IMPORTED_LOCATION "${GLOG_ROOT_DIR}/lib/libglog.so"
  INTERFACE_INCLUDE_DIRECTORIES "${GLOG_ROOT_DIR}/include"
  INTERFACE_LINK_LIBRARIES "-lpthread"
)