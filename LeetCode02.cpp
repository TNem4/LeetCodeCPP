struct ListNode 
{
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* l3 = nullptr;
        ListNode* l3Tail = nullptr;
        int rest{ -1 };
        int sum{ 0 };
        ListNode* temp;
        while (l1 != nullptr && l2 != nullptr)
        {

            sum = (l1->val + l2->val);
            if (rest != -1)
            {
                sum += rest;
                rest = -1;
            }
            if (sum >= 10)
            {
                temp = new ListNode((sum % 10));
                rest = sum / 10;;
            }
            else
            {
                temp = new ListNode(sum);
            }
            l1 = l1->next;
            l2 = l2->next;
            sum = 0;
            if (l3 == nullptr)
            {
                l3 = temp;
                l3Tail = temp;
            }
            else
            {
                l3Tail->next = temp;
                l3Tail = temp;
            }
        }
        while (l1 != nullptr)
        {
            if (rest != -1)
            {
                sum = l1->val + rest;
                rest = -1;
            }
            else
            {
                sum = l1->val;
            }
            if (sum >= 10)
            {
                temp = new ListNode((sum % 10));
                rest = sum / 10;;
            }
            else
            {
                temp = new ListNode(sum);
            }
            l1 = l1->next;
            sum = 0;
            if (l3 == nullptr)
            {
                l3 = temp;
                l3Tail = temp;
            }
            else
            {
                l3Tail->next = temp;
                l3Tail = temp;
            }

        }

        while (l2 != nullptr)
        {
            if (rest != -1)
            {
                sum = l2->val + rest;
                rest = -1;
            }
            else
            {
                sum = l2->val;
            }
            if (sum >= 10)
            {
                temp = new ListNode((sum % 10));
                rest = sum / 10;;
            }
            else
            {
                temp = new ListNode(sum);
            }
            l2 = l2->next;
            sum = 0;
            if (l3 == nullptr)
            {
                l3 = temp;
                l3Tail = temp;
            }
            else
            {
                l3Tail->next = temp;
                l3Tail = temp;
            }

        }
        if (rest != -1)
        {
            temp = new ListNode(rest);
            rest = -1;
            l3Tail->next = temp;
            l3Tail = temp;
        }
        return l3;
    }
};