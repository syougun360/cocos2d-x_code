# Cocos2d-x.Code

# はじめに。
* これはゲームではなくプログラムです。
* cocos2d-xのファイルの容量が大きかったので省きました。
* なので、コンパイル等はできませんので、ご了承ください。


# 実装内容
## Application
* Applicationを機能
* Directorのインスタンスを内包している。

## SceneManager
* シーンマネージャでの各シーンの遷移
* シーンマネージャの子オブジェクトを切り替えるやり方
    * One Scene System

## Graphics  
### Sprite
* cococs2d-xのSpriteを便利に使えるようにするクラス

### Label (Text)
* cococs2d-xのLabelを便利に使えるようにするクラス

### Point
* 点もしくは、円を作成するクラス
* 座標・半径の大きさ・色

### Triangle
* 三角形を作成できるクラス
* マイフレームの処理はない。

### Line
* 線を作成するクラス
* 始点座標・終点座標・色

### Box
* 矩形の描画ができるクラス
* 座標・サイズ・色・フレームボーダ

## InputSystem
### KeyEvent
* 押した瞬間
* 押している
* 離した瞬間

### TouchEvent
* シングルタッチ
* マルチタッチ

## AudioSystem
* BackGroundMusic
* SoundEffectMusic


## GameObject
* ゲームオブジェクトを作る基底クラス
* これを必ず継承するような形になる
* 検索・タグ機能を実装


## Component
* 挙動をコンポーネントできるクラス。
* 挙動にはこれを継承してもらう形になる。

## Hierarchy
* GameObjectをまとめているクラス。
* そこですべてのupdateを実行する

