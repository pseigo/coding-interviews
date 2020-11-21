# For debugging :)
def print_as_matrix(list):
  # src: https://stackoverflow.com/a/17871279/5164536
  print('\n'.join([''.join(['{:4}'.format(item) for item in row])
      for row in list]))
  print('\n')

def subset_sum(items, maxWeight):
  # 1-based indexing for items
  items = [0] + items

  # 2D table, rows: indices, columns: weights
  numCols = maxWeight + 1
  numRows = len(items)
  optimal = [[0 for col in range(numCols)] for row in range(numRows)]

  for i in range(1, numRows):
    for w in range(0, numCols):
      optimal[i][w] = calc_optimal(items, optimal, i, w)

  return optimal[numRows - 1][numCols - 1]

def calc_optimal(items, optimal, i, w):
  w_i = items[i]
  if w_i > w:
    return optimal[i - 1][w]

  return max(
    optimal[i - 1][w],
    w_i + optimal[i - 1][w - w_i]
  )

############ Tests ############
import unittest

class Tests(unittest.TestCase):
  def test_subset_sum(self):
    self.assertEqual(subset_sum([4, 6, 9], 11), 10)
    self.assertEqual(subset_sum([4, 2, 3], 1), 0)
    self.assertEqual(subset_sum([4, 2, 3], 2), 2)
    self.assertEqual(subset_sum([4, 2, 3], 3), 3)
    self.assertEqual(subset_sum([4, 2, 3], 4), 4)
    self.assertEqual(subset_sum([4, 2, 3], 5), 5)
    self.assertEqual(subset_sum([4, 2, 3], 6), 6)
    self.assertEqual(subset_sum([4, 2, 3], 7), 7)
    self.assertEqual(subset_sum([4, 2, 3], 8), 7)
    self.assertEqual(subset_sum([4, 2, 3], 9), 9)
    self.assertEqual(subset_sum([4, 2, 3], 10), 9)
    self.assertEqual(subset_sum([2, 2, 3], 6), 5)

if __name__ == '__main__':
    unittest.main()
