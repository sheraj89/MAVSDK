// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see https://github.com/mavlink/MAVSDK-Proto/blob/master/protos/shell/shell.proto)

#include <iomanip>

#include "shell_impl.h"
#include "plugins/shell/shell.h"

namespace mavsdk {

Shell::Shell(System& system) : PluginBase(), _impl{new ShellImpl(system)} {}

Shell::~Shell() {}

Shell::Result Shell::send(std::string command) const
{
    return _impl->send(command);
}

void Shell::subscribe_receive(receive_callback_t callback)
{
    _impl->receive_async(callback);
}

const char* Shell::result_str(Shell::Result result)
{
    switch (result) {
        case Shell::Result::Unknown:
            return "Unknown result";
        case Shell::Result::Success:
            return "Request succeeded";
        case Shell::Result::NoSystem:
            return "No system is connected";
        case Shell::Result::ConnectionError:
            return "Connection error";
        case Shell::Result::NoResponse:
            return "Response was not received";
        case Shell::Result::Busy:
            return "Shell busy (transfer in progress)";
        default:
            return "Unknown";
    }
}

std::ostream& operator<<(std::ostream& str, Shell::Result const& result)
{
    switch (result) {
        case Shell::Result::Unknown:
            return str << "Result Unknown";
        case Shell::Result::Success:
            return str << "Result Success";
        case Shell::Result::NoSystem:
            return str << "Result No System";
        case Shell::Result::ConnectionError:
            return str << "Result Connection Error";
        case Shell::Result::NoResponse:
            return str << "Result No Response";
        case Shell::Result::Busy:
            return str << "Result Busy";
        default:
            return str << "Unknown";
    }
}

} // namespace mavsdk