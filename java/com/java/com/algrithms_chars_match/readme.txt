（Let m be the length of the pattern, n be the length of the searchable text and k = |Σ| be the size of the alphabet）

        Algorithm	            Preprocessing time	        Matching time[1]        Space

Naïve string search algorithm	        none	            O(nm)	                none

Knuth–Morris–Pratt algorithm	        O(m)	            O(n)	                O(m)

Boyer–Moore string search algorithm	    O(m + k)	        best O(n/m),
                                                            worst O(mn)	            O(k)

