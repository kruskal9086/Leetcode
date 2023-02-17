class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		vector<int> v; // Declare a vector
		struct ListNode *temp;
		for(int i = 0; i < lists.size(); i++)
		{
			temp = lists[i];
			while(temp != NULL) 
			{
				v.push_back(temp -> val); // Drop all the values into the vector
				temp = temp -> next;
			}
		}
		sort(v.begin(),v.end()); // sort them
		struct ListNode *head1 = NULL;
		for(int i = 0; i < v.size(); i++)
		{
			if(head1 == NULL)  // Creating the new linked list
			{
				head1 = new ListNode(v[i]);
				temp = head1;
			}
			else
			{
				struct ListNode *nn = new ListNode(v[i]);
				temp -> next = nn;
				temp = nn;
			}
		}
		return head1;
	}
};
	