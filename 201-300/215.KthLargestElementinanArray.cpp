#include <vector>
#include <iostream>
using std::vector, std::cout, std::endl;

//better solution:
// use heap

class Solution
{
  private:
    int find(vector<int> &nums, int k, int s, int e)
    {

        int splitv = nums[s];
        int ps = s + 1;
        int pe = e - 1;
        int tmp = 0;
        while (ps <= pe)
        {
            while (nums[pe] >= splitv && ps <= pe)
                pe--;
            // fail case : [2,1 ] , 2
            //fail code: while (ps <= pe && nums[ps] <= splitv)
            //fail output :

            // =================================================================
            // ==30==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x602000000038 at pc 0x0000004062da bp 0x7fff718aebe0 sp 0x7fff718aebd8
            // READ of size 4 at 0x602000000038 thread T0
            //     #1 0x7f5cd59212e0 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x202e0)

            // 0x602000000038 is located 0 bytes to the right of 8-byte region [0x602000000030,0x602000000038)
            // allocated by thread T0 here:
            //     #0 0x7f5cd7346ce0 in operator new(unsigned long) (/usr/local/lib64/libasan.so.5+0xe9ce0)
            //     #3 0x7f5cd59212e0 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x202e0)

            // Shadow bytes around the buggy address:
            //   0x0c047fff7fb0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
            //   0x0c047fff7fc0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
            //   0x0c047fff7fd0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
            //   0x0c047fff7fe0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
            //   0x0c047fff7ff0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
            // =>0x0c047fff8000: fa fa fd fa fa fa 00[fa]fa fa fa fa fa fa fa fa
            //   0x0c047fff8010: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
            //   0x0c047fff8020: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
            //   0x0c047fff8030: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
            //   0x0c047fff8040: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
            //   0x0c047fff8050: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
            // Shadow byte legend (one shadow byte represents 8 application bytes):
            //   Addressable:           00
            //   Partially addressable: 01 02 03 04 05 06 07
            //   Heap left redzone:       fa
            //   Freed heap region:       fd
            //   Stack left redzone:      f1
            //   Stack mid redzone:       f2
            //   Stack right redzone:     f3
            //   Stack after return:      f5
            //   Stack use after scope:   f8
            //   Global redzone:          f9
            //   Global init order:       f6
            //   Poisoned by user:        f7
            //   Container overflow:      fc
            //   Array cookie:            ac
            //   Intra object redzone:    bb
            //   ASan internal:           fe
            //   Left alloca redzone:     ca
            //   Right alloca redzone:    cb
            // ==30==ABORTING

            // analyse : ps ++ make out of  nums's bound  so overflow
            // note: when debuging using clang ,no error was outputed ,but fail on leetcode
            while (ps <= pe && nums[ps] <= splitv)
                ps++;

            if (ps < pe)
            {
                tmp = nums[ps];
                nums[ps] = nums[pe];
                nums[pe] = tmp;
            }
        }
        tmp = nums[pe];
        nums[pe] = splitv;
        nums[s] = tmp;
        if (pe == k - 1)
            return splitv;
        if (pe > k - 1)
            return find(nums, k, s, pe);
        else
            return find(nums, k, pe + 1, e);
    }

  public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int l = nums.size();
        if (k <= 0 || k > l)
            return 0;
        return find(nums, l + 1 - k, 0, l);
    }
};

int main()
{

    Solution s;
    // auto v = vector<int>{3, 2, 1, 5, 6, 4};
    // cout << s.findKthLargest(v, 2) << endl;
    // auto vv = vector<int>{3, 2, 3, 1, 2, 4, 5, 5, 6};
    // cout << s.findKthLargest(vv, 4) << endl;
    // auto vvv = vector<int>{6};
    // cout << s.findKthLargest(vvv, 1) << endl;
    // auto vvvv = vector<int>{-1, 2, 0};
    // cout << s.findKthLargest(vvvv, 1) << endl;
    auto vvvvv = vector<int>{2, 1};
    cout << s.findKthLargest(vvvvv, 2) << endl;
    return 0;
}