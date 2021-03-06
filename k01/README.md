# 課題1 レポート
学籍番号　氏名


## 課題
長崎県にある市町村別人口データを読み込み、IDを用いて検索し、該当する市町村名、人口を出力するプログラムを作成する。

1. 使用するデータ
長崎県の人口データは、nagasaki.csvに保存されている。
nagasaki.csvには、csv形式で以下のデータが含まれる
    - ID
    - 県名
    - 市町村名
    - 人口
    - 男性人口
    - 女性人口

    長崎県の市町村別人口データは、下記に構造体の配列に読み込まれる。

```C: 市町村別データ構造体
typedef struct {  
    int id;  
    char pref[13];  // UTF-8対応  
    char name[19];  // UTF-8対応  
    int population;  
    int m_population;  
    int f_population;  
} City;  
```



2. 必須問題：実装する関数  
本課題では、以下の関数を実装する。  
   (1) LinearSearch：IDをキーとし、リニアサーチで市町村を検索する。  
    [入力]
    - int key: 検索する市町村のID
    - City arrayCity[]: 検索対象の都市別人口データ(配列)
    - int size: データの数  

    [出力]  
    - return値: IDが合致した配列データのindex。IDが一致するデータがない場合は-1。

    (2) BinarySearch: IDをキーとし、バイナリサーチで市町村を検索する。  
    [入力]
    - int key: 検索する市町村のID
    - City arrayCity[]: 検索対象の都市別人口データ(配列)
    - int left: バイナリサーチを行う配列のindex(左端)
    - int right: バイナリサーチを行う配列のindex(右端)  

    [出力]  
    - return値: IDが合致した配列データのindex。IDが一致するデータがない場合は-1。


3. 補助関数
以下の関数はすでに実装されており、利用することができる。  
- PrintCity: 特定の市町村別人口データを出力する  
- PrintArray: 市町村別人口データをすべて出力する  
- LoadData: 市町村別人口データを読み込み、City型の配列に格納する  
- main: メイン関数。データをロードし、リニアサーチ、バイナリサーチを呼び出す  


## ソースコードの説明
必須問題1
68~69.変数を用意し、結果を見つからないようにする
71.比較対象の位置を先頭にする
73.keyとidが一致した場合その位置を結果に入れる
74.繰り返しを抜ける
75.不一致な場合resultの値を返す

必須問題2
85~86.変数を定義し結果を見つからないようにする
87~88.リストの右端と左端を0とリストの最後のindexにする
90.条件を満たすと繰り返し処理を行う
92.比較対象をリストの真ん中にする
93,98,102.探す値と比較するものの一の比較をする
95.keyとidが一致した場合その位置を結果に入れる
96.繰り返しを抜ける
100.keyがidより大きかった場合1つ右にずらす
105.keyがidより小さかった場合1つ左にずらす
109.resultの値を返す

## 出力結果

```
===== linear search =====
City ID?42001
city was not found

===== binary search =====
City ID?42201
42201, 長崎県, 長崎市, 429508, 198716, 230792

```

## 修正履歴

