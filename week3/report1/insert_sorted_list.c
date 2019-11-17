/*配列の要素数*/
#define SIZE 100
/*配列を要素数SIZEで宣言，0で初期化*/
static int ARRAY[SIZE] = {};

/*配列のどこまで要素が代入されたかを示す変数*/
int ARRAYEND = 0;
/**
 * @brief 配列の中身を3桁ごとに表示する関数
 * @return なし
 */
void print_array()
{
    int i;
    /*配列の中身全てではなく代入された要素だけを表示*/
    for (i = 0; i < ARRAYEND; ++i)
    {
        printf("%3d,", ARRAY[i]);
    }
    printf("\n");
}

/**
 * @brief 配列の要素を昇順にソートする関数
 * @return なし
 */
void asc_sort_array()
{
    int i, j, temp;
    for (i = 0; i < ARRAYEND; ++i)
    {
        for (j = i + 1; j < ARRAYEND; ++j)
        {
            /*i番目の要素より小さい要素があったら入れ替える*/
            if (ARRAY[i] > ARRAY[j])
            {
                temp = ARRAY[i];
                ARRAY[i] = ARRAY[j];
                ARRAY[j] = temp;
            }
        }
    }
}

/**
 * @brief 配列の中にkeyと同値が存在するか探索し昇順にソートする．
 * @param key:配列に格納したい変数
 * @return 配列に既にkeyが存在すれば1(Yesの意味)
 * 　　　　 存在しなければ0(Noの意味)
 */
int insert_sorted_list(int key)
{
    printf("insert:%d\n",key);
    int i;
    /*配列の中にkeyと同じ要素がないか探索する*/
    for (i = 0; i < ARRAYEND; ++i)
    {
        if (ARRAY[i] == key)
        {
            /*存在した場合ソートだけ行う*/
            asc_sort_array();
            printf("Yes\n");
            print_array();
            return 1;
        }
    }
    /*存在しなかった場合，配列の後ろにkeyの値を代入*/
    ARRAY[ARRAYEND] = key;
    /*どこまで代入したかを示すARRAYENDをインクリメント*/
    ARRAYEND++;
    /*ソートを実行*/
    asc_sort_array();
    printf("No\n");
    print_array();
    return 0;
}