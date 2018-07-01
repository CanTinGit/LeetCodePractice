# LeetCode Note
26\. Remove Duplicates from sorted array：要得到时间复杂度最低的解，并不需要每次找到重复就移除，因为已经是有序数组，可以从0开始遍历，依次保留0,1,2........检测到重复的值，直接移动至末尾，最后一次全部移除（resize）即可。

35\. Binary search: 改变max和min的值的时候要多一位，即min=mid+1，max=mid-1，这样才能保证遍历完整个数组。用while循环更方便

53\. Maximum Subarray: 每次遍历，用当前和加上当前数组的值，然后与目前最大值比较，如果大于最大值，则更新最大值为和，否则不更新，然后与0比较，若大于0则保留当前和否则设当前和为0。这样只需一次遍历即可。（即永远比较当前数组值和它下一位加起来之和是否大于原值，若大于则更新最大值否则后移，同时比较目前的加和是否大于0，若大于则还可以往后加，若已经不大于0，则意味后面的值带来的是当前最大值的减少，就一定不可能是最后想要的最大值）
