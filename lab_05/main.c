#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define UNCORRECT_SYMBOL -1;
#define OK 0;

double *get_array_from_keyboard(int n,int m, int *count_non_zero, int *count_elemnts)
{
  FILE *f;
  int i = 0;
  int c;
  double num;
  *count_non_zero = 0;
  *count_elemnts = 0;

  f = fopen("in.txt","w");

  c = getchar();

  for(i = 0; i< n; i++)
  {
    printf("Введите элементы %d-й строки через пробел: ",(i+1));
    while((c = getchar()) != '\n')
    {
      fprintf(f, "%c", c);
      if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
      {
        printf("Вы ввели некорректный символы\n");
        return NULL;
      }
    }
    fprintf(f, "\r\n");
  }

  fclose(f);

  f = fopen("in.txt","r");
  if(!f)
  {
    printf("Ошибка файла\n");
    return NULL;
  }
  else
  {
    if(fscanf(f,"%lf",&num) == 1)
    {
      if(num != 0)
        *count_non_zero = *count_non_zero + 1;
      while(fscanf(f,"%lf",&num) == 1)
        if(num != 0)
          *count_non_zero = *count_non_zero + 1;
    }
  }

  fclose(f);

  double *matrix = malloc(*count_non_zero * sizeof(double));
  i = 0;
  f = fopen("in.txt","r");
  if(!f)
  {
    printf("Ошибка файла\n");
    return NULL;
  }
  else
  {
    if(fscanf(f,"%lf",&num) == 1)
    {
      *count_elemnts = *count_elemnts + 1;

      if(num != 0)
      {
        matrix[i] = num;
        i++;
      }
      while(fscanf(f,"%lf",&num) == 1)
      {
        *count_elemnts = *count_elemnts + 1;
        if(num != 0)
        {
          matrix[i] = num;
          i++;
        }
      }
    }
  }
  fclose(f);

  if(*count_elemnts != n * m)
  {
    printf("Неверное количество элементов\n");
    return NULL;
  }

  return matrix;
}

int *get_ia(int m,int *count_non_zero)
{
  FILE *f;
  int fill_rows = 0;;
  double num;
  int waddap = 0;
  int i = 0;
  int *IA = malloc(*count_non_zero * sizeof(int));

  f = fopen("in.txt","r");
  if(!f)
    return NULL;
  else
  {
    if(fscanf(f,"%lf",&num) == 1)
    {
      if(num != 0)
      {
        IA[i] = waddap;
        i++;
      }

      fill_rows++;
      if(fill_rows == m)
      {
        waddap++;
        fill_rows = 0;
      }
      while(fscanf(f,"%lf",&num) == 1)
      {
        if(num != 0)
        {
          IA[i] = waddap;
          i++;
        }

        fill_rows++;
        if(fill_rows >= m)
        {
          waddap++;
          fill_rows = 0;
        }
      }
    }
  }
  fclose(f);

  return IA;
}

void get_ja(int n, int m,int count_elemnts, int count_non_zero)
{
  int i = 0;
  int j = 0;

  FILE *f;
  double num;

  double *matrix = malloc(count_elemnts * sizeof(double));

  f = fopen("in.txt","r");
  if(!f)
  {
    printf("Ошибка файла\n");
    //return NULL;
  }
  else
  {
    if(fscanf(f,"%lf",&num) == 1)
    {
      matrix[i] = num;
      i++;
      while(fscanf(f,"%lf",&num) == 1)
      {
        matrix[i] = num;
        i++;
      }
    }
  }
  fclose(f);

  int *ia = calloc(m+1,sizeof(int));

  for(i = 0; i < m+1; i++)
    ia[i] = 0;

  ia[0] = count_non_zero+1;

  j = 1;
  int c_n_z = count_non_zero;
  i = (n * m) - 1;
  while(i >= 0)
  {
    if(j == m + 1)
      j = 1;
    if(matrix[i] != 0)
    {
      ia[j] = c_n_z;
      c_n_z--;
    }
    j++;
    i--;
  }

  for(i = 0; i < m+1; i++)
  {
    if(ia[i] == 0)
      ia[i] = ia[i-1];
  }

  printf("INDEXES: ");
  for(i = m; i >= 0; i--)
    printf("%d ", ia[i]);

}

int main(void)
{
  int n = 0;
  int m = 0;
  int count_non_zero;
  int count_elemnts;

  double *A;
  int *IA;

  printf("Введите количество строк: ");
  scanf("%d",&n);
  if(n > 0)
  {
    printf("Введите количество столбцов: ");
    scanf("%d",&m);
    if(m > 0)
    {
      A = get_array_from_keyboard(n, m, &count_non_zero, &count_elemnts);
      IA = get_ia(m,&count_non_zero);
      if(A)
      {
        printf("A: ");
        for(int i = 0; i < count_non_zero;i++)
          printf("%f ", A[i]);
        printf("\n");
        printf("IA: ");
        for(int i = 0; i < count_non_zero; i++)
          printf("%d ", IA[i]+1);
        printf("\n");
        get_ja(n, m, count_elemnts, count_non_zero);
      }
    }
    else
      printf("Некорректное количество столбцов\n");
  }
  else
    printf("Некорректное количество строк\n");

}