/*
 * LCR 182. 动态口令  简单
 * Created Time: 2024-09-24
 * https://leetcode.cn/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/description/
 * 某公司门禁密码使用动态口令技术。初始密码为字符串 password，密码更新均遵循以下步骤：
 * 设定一个正整数目标值 target，将 password 前 target 个字符按原顺序移动至字符串末尾。
 * 请返回更新后的密码字符串。
 */
 
#include "HEADER.hpp"

class Solution {
public:
    std::string dynamicPassword(std::string password, int target) {
        return password.substr(target) + password.substr(0, target);
    }
};

int main() {
    return 0;
}