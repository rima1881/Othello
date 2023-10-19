#include <string>
class Error
{
private:
    std::string msg;
public:

    Error(std::string);
    std::string getMsg();

};