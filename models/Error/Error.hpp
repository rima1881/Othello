#include <string>
class Error
{
private:
    static std::string errorMessages[2];
    int code;
public:

    Error(int);
    std::string getMsg();
    int getCode();

};