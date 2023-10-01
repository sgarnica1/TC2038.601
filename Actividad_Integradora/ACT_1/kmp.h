/**
 * @file kmp.h
 * @brief Knuth-Morris-Pratt algorithm for string matching (KMP)
 * @details
 * The Knuth-Morris-Pratt algorithm is a string matching algorithm that finds the
 * occurrence of a pattern in a text. It uses the information about the previous
 * matches to determine where the next match could begin, thus improving the
 * overall performance of the algorithm.
 */

#ifndef KMP_H
#define KMP_H

#include <bits/stdc++.h>

void computeLPSArray(char *pat, int M, int *lps);

// Prints occurrences of txt[] in pat[]
void KMPSearch(char *pat, char *txt)
{
  int M = strlen(pat); // M = length of the pattern
  int N = strlen(txt); // N = length of the text
  int lps[M];

  // Calculate lps[] that will hold the longest prefix suffix
  computeLPSArray(pat, M, lps);

  int txt_index = 0;
  int pat_index = 0;
  bool found = false;
  while ((N - txt_index) >= (M - pat_index))
  {
    if (pat[pat_index] == txt[txt_index])
    {
      pat_index++;
      txt_index++;
    }

    if (pat_index == M)
    {
      std::cout << "(true) Posicion inicial: " << txt_index - pat_index << " ";
      std::cout << "Posicion final: " << txt_index - 1 << "\n";
      found = true;
      pat_index = lps[pat_index - 1];
    }

    else if (txt_index < N && pat[pat_index] != txt[txt_index])
    {
      if (pat_index != 0)
        pat_index = lps[pat_index - 1];
      else
        txt_index = txt_index + 1;
    }
  }
  if (!found)
    std::cout << "(false) Cadena no encontrada en la transmision\n";
}

/**
 * @brief
 * Computes the longest prefix suffix for the pattern
 * @param pat - Pattern to be searched
 * @param M - Length of the pattern
 * @param lps - Array to store the longest prefix suffix
 * @return void
 * @Time Complexity - O(M)
 * @Space Complexity - O(M)
 */
void computeLPSArray(char *pat, int M, int *lps)
{
  int len = 0; // length of the previous longest prefix suffix
  lps[0] = 0;  // LPS = Longest Prefix Suffix Array

  // Loop to calculate lps[i] for i = 1 to M-1
  int i = 1;
  while (i < M)
  {
    if (pat[i] == pat[len])
    {
      len++;
      lps[i] = len;
      i++;
    }
    else // (pat[i] != pat[len])
    {
      if (len != 0)
        len = lps[len - 1];
      else // if (len == 0)
      {
        lps[i] = 0;
        i++;
      }
    }
  }
}

#endif // KMP_H