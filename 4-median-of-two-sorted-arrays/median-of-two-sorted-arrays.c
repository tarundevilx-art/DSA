double findMedianSortedArrays(int* nums1, int m, int* nums2,int n) {
   if(m>n){
    return findMedianSortedArrays(nums2,n,nums1,m);
   } 
   int low=0;
   int high=m;

   while(low<=high){
    int partition1=(low + high)/2 ;
    int partition2=(m+n+1)/2-partition1 ;

    int left1;
    int right1;
    int left2;
    int right2;

    if (partition1 == 0)
            left1 = INT_MIN;
    else
            left1 = nums1[partition1 - 1];

    if (partition1 == m)
            right1 = INT_MAX;
    else
            right1 = nums1[partition1];

    if (partition2 == 0)
            left2 = INT_MIN;
    else
            left2 = nums2[partition2 - 1];
    if (partition2 == n)
            right2 = INT_MAX;
    else
            right2 = nums2[partition2];

        // Correct partition
    if (left1 <= right2 && left2 <= right1) {

            // Total elements are odd
        if ((m + n) % 2 == 1) {
                return (double)(left1 > left2 ? left1 : left2);
            }

            // Total elements are even
            int maxLeft = left1 > left2 ? left1 : left2;
            int minRight = right1 < right2 ? right1 : right2;

            return (maxLeft + minRight) / 2.0;
        }

        // Move partition1 to the left
    else if (left1 > right2) {
            high = partition1 - 1;
        }

        // Move partition1 to the right
    else {
            low = partition1 + 1;
        }
    }
    return 0.0;


   }
