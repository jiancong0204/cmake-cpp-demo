#ifndef LOGGER_LOGGER_H
#define LOGGER_LOGGER_H

#include <gflags/gflags.h>
#include <glog/logging.h>

#include <string>

namespace Logger {
using std::string;

static const string RED = "\033[31m";
static const string GREEN = "\033[32m";
static const string YELLOW = "\033[33m";
static const string BLUE = "\033[34m";
static const string MAGENT = "\033[35m";
static const string CYAN = "\033[36m";
static const string END = "\033[0m";

static void Init(const char* argv0)
{
    google::InitGoogleLogging(argv0);
    FLAGS_logtostderr = true;
    FLAGS_colorlogtostderr = true;
}

static void Stop()
{
    google::ShutdownGoogleLogging();
}
} // namespace Logger

#endif // LOGGER_LOGGER_H