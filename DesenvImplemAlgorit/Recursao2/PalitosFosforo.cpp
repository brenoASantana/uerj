/*
A representação decimal dos números pode ser facilmente feita com palitos de fósforo. Cada algarismo pode ser representado conforme ilustra a figura abaixo.



Elabore um programa para, dados dois naturais n,k, determinar quantos números de exatamente k algarismos podem ser escritos com no máximo n palitos.

Haverá vários casos de teste. A primeira linha contém um inteiro t (1 ≤ t ≤ 5000), que indica o número de casos de teste. Cada teste vem em uma única linha,
contendo dois inteiros 0 ≤ n ≤ 10^9, 1 ≤ k ≤ 18.

Saída

Para cada caso de teste, escreva em uma linha com a quantidade de números com exatamente k algarismos podem ser representados com no máximo n palitos.
*/

#include <iostream>
#include <vector>
using namespace std;

// Função que realiza a mescla contando as inversões
long long merge_and_count(vector<int> &arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> left(n1), right(n2);
    for (int i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    long long inv_count = 0;

    // Mescla os vetores e conta as inversões:
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
            // Se left[i] > right[j], todos os elementos restantes em left[i...n1-1] são maiores que right[j]
            inv_count += (n1 - i);
        }
    }

    // Copia os elementos restantes (caso haja)
    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];

    return inv_count;
}

// Função merge sort modificada que utiliza recursão para contar inversões
long long mergeSort_and_count(vector<int> &arr, int l, int r)
{
    long long inv_count = 0;
    if (l < r)
    {
        int m = l + (r - l) / 2;
        inv_count += mergeSort_and_count(arr, l, m);     // Chamada recursiva para a metade esquerda
        inv_count += mergeSort_and_count(arr, m + 1, r); // Chamada recursiva para a metade direita
        inv_count += merge_and_count(arr, l, m, r);      // Mescla e contagem das inversões
    }
    return inv_count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        long long inversions = mergeSort_and_count(arr, 0, n - 1);
        cout << inversions << "\n";
    }

    return 0;
}
