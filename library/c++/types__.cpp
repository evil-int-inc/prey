#include <map>

typedef std::function<void()> react_callback;
typedef std::vector<react_callback> react_callback_vector;
typedef std::map<std::string, react_callback> react_callback_map;
