#include <string>
class Error
{
private:
    std::string msg;
public:

    Error(std::string msg);
    std::string getMsg();

};