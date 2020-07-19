int twoSum(int nums,int target){
	int start=0;
	int end = nums.length - 1;
	int* result = new int[2];

	while(start < end){
		int sum = nums[start] + nums[end];
		if(sum == target){
			result[0] = start + 1;
			result[0] = end + 1;
			break;
		}else if (sum < target){
			start++;
		}else{
			end--;
		}
	}
	return result;
}