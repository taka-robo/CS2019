/**
 * @fn
 * @brief 自然数Nまでの自然数i,jの組の最大公約数が1だったとき配列の対応する箇所に1を格納する
 * @param 自然数N
 * @param 計算結果を格納する配列
 * @return なし
 */
void getCoprime(int64_t N, std::vector<std::vector<bool>> &isCoprime)
{
    //時間計測開始
    auto start = std::chrono::system_clock::now();
    //N+1×N+1のbool型のvectorを1で再定義
    isCoprime.assign(N + 1, std::vector<bool>(N + 1, true));
    int64_t i, j, k;
    //互いに素である組の倍数を削除していくアルゴリズム
    for (i = 1; i <= N; ++i)
    {
        //i,jの組を逆にしても結果は同じなのでj=iから探索する
        for (j = i; j <= N; ++j)
        {
            //互いに素でなければすでにその先の倍数は探索済みなのでjをカウントアップ
            if (!isCoprime[i][j])
            {
                continue;
            }
            //i,jの組の倍数を消していく
            for (k = 2; j * k <= N; ++k)
            {
                isCoprime[i * k][j * k] = false;
                // i,jが逆の組も最大公約数の結果は一緒
                isCoprime[j * k][i * k] = false;
            }
        }
    }
    //時間計測終了
    auto end = std::chrono::system_clock::now();
    // 時間の出力（今回はミリ秒（1/1000秒）を使用）
    std::cout << __func__ << ":" << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "[ms]" << std::endl;
}

/**
 * @fn
 * @brief エラトステネスの篩を実行する関数(自然数Nまでの素数を探索する)
 * @param 自然数N
 * @param 計算結果を格納する配列
 * @return なし
 */
void sieveOfEratosthenes(int64_t N, std::vector<bool> &isPrime)
{
    //時間計測開始
    auto start = std::chrono::system_clock::now();
    //isPrimeのサイズを変更し配列の要素をtrueで再定義
    isPrime.assign(N + 1, true);
    int64_t i, j, sqrtN;
    //√Nを計算（誤差を考慮して+1している)
    sqrtN = std::sqrt(N) + 1;
    //√Nまで探索
    for (i = 2; i <= sqrtN; ++i)
    {
        //素数でなければすでにその先の倍数は探索済みなのでiをカウントアップ
        if (!isPrime[i])
        {
            continue;
        }
        //jをi*iからスタート（それより小さい値はすでに探索済みのはずなので)
        for (j = i * i; j <= N; j += i)
        {
            isPrime[j] = false;
        }
    }
    // 0と1は素数じゃないので強制的にfalse:w
    isPrime[0] = false;
    isPrime[1] = false;
    //時間計測終了
    auto end = std::chrono::system_clock::now();
    // 時間の出力（今回はミリ秒（1/1000秒）を使用）
    std::cout << __func__ << ":" << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "[ms]" << std::endl;
}