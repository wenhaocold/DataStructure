#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <vector>
#include <sys/timeb.h>
#include <set>

std::vector<int>*  multiTwoNum(const std::vector<int>& lNum, const std::vector<int>& rNum, int power)
{
    int length = rNum.size();
    std::list<int> l_result[length];
    int jwFlag = 0;
    int lastJwFlag = 0;
    int n_result = 0;
    for (int i = 0; i < length; i++)
    {
        jwFlag = 0;
        lastJwFlag = 0;
        for (int j = 0; j < lNum.size(); j++)
        {
            n_result = rNum.at(i) * lNum.at(j);
            if (1 == lastJwFlag)
            {
                int result = l_result[i].back();
                l_result[i].pop_back();
                n_result += result;
            }
            if (n_result >= 10)
            {
                jwFlag = 1;
            }
            else
            {
                jwFlag = 0;
            }
            if (1 == jwFlag)
            {
                l_result[i].push_back(n_result % 10);
                l_result[i].push_back(n_result / 10);
            }
            else
            {
                l_result[i].push_back(n_result);
            }

            lastJwFlag = jwFlag;
        }

    }

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < i; j++)
        {
            l_result[i].push_front(0);
        }
    }

    n_result = 0;
    jwFlag = 0;
    lastJwFlag = 0;
    std::list<int> ret;
    while (!l_result[length - 1].empty())
    {
        n_result = 0;
        for (int i = 0; i < length; i++)
        {
            if (!l_result[i].empty())
            {
                n_result += l_result[i].front();
                l_result[i].pop_front();
            }
        }

        if ( 1 == lastJwFlag )
        {
            int result = ret.back();
            ret.pop_back();
            n_result += result;
        }

        if (n_result >= 10)
        {
            jwFlag = 1;
        }
        else
        {
            jwFlag = 0;
        }
        if (1 == jwFlag)
        {
            ret.push_back(n_result % 10);
            ret.push_back(n_result / 10);
        }
        else
        {
            ret.push_back(n_result);
        }

        lastJwFlag = jwFlag;
    }

    std::vector<int>* v_ret = new std::vector<int>;

    for (auto iter = ret.begin(); iter != ret.end(); ++iter)
    {
        v_ret->push_back(*iter);
    }

//    for (auto iter = v_ret->rbegin(); iter != v_ret->rend(); iter++)
//    {
//        std::cout << *iter;
//    }
//    std::cout << std::endl;

    if (power > 2)
    {
        power--;
        return multiTwoNum(lNum, *v_ret, power);
    }
    else
    {
        return v_ret;
    }
}

std::vector<int>* NumPower(const std::vector<int>& num, int power)
{
//    std::cout << "====b======" << std::endl;
        return multiTwoNum(num, num, power);
//    for (auto iter = p->rbegin(); iter != p->rend(); iter++)
//    {
//        std::cout << *iter;
//    }
//    std::cout << "=====e=====" << std::endl;
}

int getZeroAfterDot(std::vector<int>& Decimal)
{
    int zeroNum = 0;
    for (auto iter = Decimal.rbegin(); iter != Decimal.rend(); ++iter)
    {
        if (0 == Decimal.back())
        {
            if (0 != *iter)
            {
                break;
            }
            else
            {
                zeroNum++;
            }
        }
    }
    std::cout << "zeroNum = " << zeroNum << std::endl;
    return zeroNum;
}

std::string getNumberOfPowerAndIntegerAndDecimal(
         std::vector<int>& v_Integer,  std::vector<int>& v_Decimal, int power)
{
    int zeroNum = 0;

    zeroNum = getZeroAfterDot(v_Decimal);

    for (int i = 0; i < zeroNum; i++)
    {
        v_Decimal.pop_back();
    }

//    std::cout << "after pop zero:"<< std::endl;
//    for (auto iter = v_Integer.rbegin(); iter != v_Integer.rend(); ++iter)
//    {
//        std::cout << *iter;
//    }
//    std::cout << ".";
//    for (auto iter = v_Decimal.rbegin(); iter != v_Decimal.rend(); ++iter)
//    {
//        std::cout << *iter;
//    }
//    std::cout << std::endl;

    std::vector<int>* p_Integer = NumPower(v_Integer, power);
    std::vector<int>* p_Decimal = NumPower(v_Decimal, power);

    std::string result;

    for (auto iter = p_Integer->rbegin(); iter != p_Integer->rend(); iter++)
    {
        result.push_back(*iter + '0');
//        std::cout << *iter;
    }
    result.push_back('.');
//    std::cout << ".";

    for (int i = 0; i < zeroNum * power; i++ )
    {
        result.push_back('0');
//        std::cout << 0;
    }
    for (auto iter = p_Decimal->rbegin(); iter != p_Decimal->rend(); iter++)
    {
        result.push_back(*iter + '0');
//        std::cout << *iter;
    }

    return result;
}



std::string getNumberOfPower(std::string strNum, int power)
{
    std::cout << strNum << std::endl;
    std::cout << power  << std::endl;

    int dotPos = strNum.find('.');
    int integerLen = dotPos - 0;
    int decimalLen = strNum.length() - integerLen - 1;

    std::vector<int> l_Integer;
    std::vector<int> l_Decimal;


    for (int i = 0; i < integerLen; i++)
    {
        l_Integer.push_back(strNum[integerLen - i - 1] - 0x30);
    }

    for (int i = strNum.length() - 1; i > dotPos; i--)
    {
        l_Decimal.push_back(strNum[i] - 0x30);
    }



    for (auto iter = l_Integer.rbegin(); iter != l_Integer.rend(); ++iter)
    {
        std::cout << *iter;
    }
    std::cout << ".";
    for (auto iter = l_Decimal.rbegin(); iter != l_Decimal.rend(); ++iter)
    {
        std::cout << *iter;
    }

    std::cout << std::endl;


    std::string result = getNumberOfPowerAndIntegerAndDecimal(l_Integer,
                                                l_Decimal, power);


    return result;
}
//
//int main(int argc,char *argv[])
//{
//    argc = 3;
//    argv[1] = "0.4321";
//    argv[2] = "20";
//
//    if (argc <= 1)
//	{
//		std::cout << "please input number!!" << std::endl;
//		return 0;
//	}
//	else if (argc <= 2)
//	{
//		std::cout << "please input power!!" << std::endl;
//		return 0;
//	}
//
//	std::string strNum = argv[1];
//	int power = atoi(argv[2]);
//
//    struct timeb time1;
//    struct timeb time2;
//    ftime(&time1);
////    std::string result = getNumberOfPower(strNum, power);
//    ftime(&time2);
//
//    //=========
//
//    std::cout << strNum << std::endl;
//    std::cout << power  << std::endl;
//
//    int dotPos = strNum.find('.');
//    int integerLen = dotPos - 0;
//    int decimalLen = strNum.length() - integerLen - 1;
//
//    std::vector<int> l_Integer;
//    std::vector<int> l_Decimal;
//
//    std::vector<int> numTest;
//
//    for (int i = strNum.length() - 1; i > dotPos; i--)
//    {
//        numTest.push_back(strNum[i] - 0x30);
//    }
//    for (int i = 0; i < integerLen; i++)
//    {
//        numTest.push_back(strNum[integerLen - i - 1] - 0x30);
//    }
//
//    for (auto iter = numTest.rbegin(); iter != numTest.rend(); ++iter)
//    {
//        std::cout << *iter;
//    }
//    std::cout << std::endl;
//
//    ftime(&time1);
//    std::vector<int>* p_Integer = NumPower(numTest, power);
//    ftime(&time2);
//    for (auto iter = p_Integer->rbegin(); iter != p_Integer->rend(); ++iter)
//    {
//        std::cout << *iter;
//    }
//    std::cout << std::endl;
//
//
//    //==========
//
////    std::cout << "result = " << result << std::endl;
//    std::cout << "用时" << time2.millitm - time1.millitm
//              << "毫秒" << std::endl;
//
//    return 0;
//}

using namespace std;

int lengthOfLongestSubstring(string s) {
    if (s.empty()) return 0;
    if (s.size() == 1) return 1;
    vector<int> last(255, -1);
    int start = 0;
    int maxLen = 1;
    for (int i = 0; i < s.size(); i++) {
        if (last[s[i]] >= start) {
            maxLen = max(maxLen, i - start);
            start = last[s[i]] + 1;
        }
        last[s[i]] = i;
    }
    return max((int)s.size() - start, maxLen);
}


int main()
{
    int result = lengthOfLongestSubstring("hkhj");
    cout << result << endl;
}