class Solution{
public:	
    int findKRotation(int arr[], int n) {
        int low = 0, high = n - 1;
        
        // If the array is not rotated, return 0
        if (arr[low] <= arr[high]) return 0;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int next = (mid + 1) % n; // Handling boundary case for mid+1
            int prev = (mid - 1 + n) % n; // Handling boundary case for mid-1
            
            if (arr[mid] < arr[next] && arr[mid] < arr[prev]) {
                return mid;
            } else if (arr[mid] < arr[high]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return 0;
    }
};