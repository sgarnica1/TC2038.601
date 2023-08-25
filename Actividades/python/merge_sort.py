def merge(arr1: list, arr2: list) -> list:
    ordered_array = []
    while(len(arr1) > 0 and len(arr2) > 0):
      if(arr1[0] > arr2[0]):
        ordered_array.append(arr1.pop(0))
      else: 
        ordered_array.append(arr2.pop(0))

    # Add remaining elements of arr1 or arr2
    ordered_array.extend(arr1)
    ordered_array.extend(arr2)

   
    return ordered_array


def merge_sort(arr: list) -> list:
    
    if(len(arr) == 1):
        return arr
    
    arr1 = arr[:len(arr)//2]
    arr2 = arr[len(arr)//2:]

    arr1 = merge_sort(arr1)
    arr2 = merge_sort(arr2)

    return merge(arr1, arr2)

def run():
    n = input('Enter your list length: ')
    numbers = []

    for _ in range(0,int(n)):
       digit = input('Enter a number: ')
       numbers.append(int(digit))
      
    print(f'\nYour unsorted list: {numbers}')
    
    sorted_numbers = merge_sort(numbers)
    print("\nSorting numbers from bigger to smaller...")
    print(f'\nAfter merge sort: {sorted_numbers}')

if __name__ == "__main__":
    run()