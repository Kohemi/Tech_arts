# Data Mining

데이터 마이닝은 대용량 데이터에서 중요한 정보를 뽑아내고 의미를 도출하는 절차를 의미

## 1주차. 빈발 아이템 찾기

### Motivations

#### Market-Basket Model 응용

* 관련 아이템들을 서로 묶어 놓는 것

* 빈번히 나타나는 규칙 파악

* Baskets = Sentences; Items = documents containing those sentences
  -> Items that appear together too often may represent plagiarism
* Baskets = users; items = movies that each user has watched
* Market-Basket Model은 다양한 데이터에 적용 가능한 굉장히 범용적인 기법

### Frequent Itemsets

* Goal : Find sets of items that appear together "frequently" in baskets
* Support(for itemset I) : number of baskets containing all items in I
* Frequent itemstes : sets of items that appear in >= s baskets

* s is called minimum support
* What is the support of the itemset containing diaper and milk? => To compute it, we investigate each basket and count the number of baskets containing diaper and milk. 

#### Association Rules

* 연관 규칙 중 중요한 또는 흥미로운 규칙을 찾는 것이 중요
* Confidence of a rule is the probability of j given I : I 를 구매했을 때 j를 살 확률
* 일반적으로 confidence가 높은 규칙이 낮은 규칙보다는 낫다.

#### Interesting Association Rules

* Confidence 개념을 보완하기 위해 Interest가 나옴 
* I 에서 j 로 가는 규칙의 interest는 I에서 j로 가는 규칙의 confidence에서 j가 나올 확률을 빼는 것 

#### Challenge of too many itemsets

* Itemset의 길이가 길어지면 부분집합의 개수가 굉장히 커지게 됨
* 빈발 Itemst의 개수를 줄이는 것 
* Maximal frequent itemsets : 특정 itemset보다 더 빈발한 itemset, 즉 더 자주 나타나는 superset이 존재하지 않음
* Closed frequent itemset은 superset인데 같은 support를 갖는 frequent한 set이 없다는 걸 의미.

#### Finding Association Rules

* 최소 s번 나타나고 confidence가 최소 c는 되는 규칙을 찾는 것

#### Mining Association Rules

Step 1. Find  all frequent itemsets I

Step 2. Generate rules

### Finding frequent itemsets

#### Computational Model

* 어떤 알고리즘을 만들었을 때 알고리즘의 성능을 평가하는 기준은 disk I/Os
* 디스크에 얼마나 접근하는지가 가장 큰 시간을 결정하는 요인
* 어떠 데이터가 디스크에 저장되어 있을 때 데이터를 처음부터 끝까지 쭉 읽는 걸 pass
* pss는 순차접근을 하게 되는데 일반적으로 순차접근이 random access보다 훨씬 빠름
* 그래서 순차접근을 몇 번 하는지에 따라서 알고리즘의 성능을 평가 
* 1-pass 알고리즘 : 데이터를 처음부터 끝까지 순차적으로 쭉 읽으면 결과가 나오는 것, 2-pass 알고리즘 : 한번 읽고 또 한 번 읽어야 결과가 나오는 것

#### Main-Memory Bottleneck

메모리를 어떻게 효율적으로 사용는지가 빈발 아이템 알고리즘의 가장 중요한 이슈

#### Finding frequent Pairs