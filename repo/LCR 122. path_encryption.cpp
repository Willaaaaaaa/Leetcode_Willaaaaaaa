/*
 * LCR 122. 路径加密  简单
 * Created Time: 2024-09-24
 * https://leetcode.cn/problems/ti-huan-kong-ge-lcof/description/
 * 假定一段路径记作字符串 path，其中以 "." 作为分隔符。
 * 现需将路径加密，加密方法为将 path 中的分隔符替换为空格 " "，请返回加密后的字符串。
 */
 
#include "HEADER.hpp"

class Solution1 {
public:
    std::string pathEncryption(std::string path) {
        std::replace(path.begin(), path.end(), '.', ' ');
        return path;
    }
};

class Solution2 {
public:
    std::string pathEncryption(std::string path) {
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '.') {
                path[i] = ' ';
            }
        }
        return path;
    }
};

int main() {
    return 0;
}