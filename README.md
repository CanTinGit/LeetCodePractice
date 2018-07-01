# LeetCode Note
26. Remove Duplicates from sorted array：要得到时间复杂度最低的解，并不需要每次找到重复就移除，因为已经是有序数组，可以从0开始遍历，依次保留0,1,2........检测到重复的值，直接移动至末尾，最后一次全部移除（resize）即可。
35. Binary search: 改变max和min的值的时候要多一位，即min=mid+1，max=mid-1，这样才能保证遍历完整个数组。用while循环更方便

