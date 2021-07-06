# 소개
구면 영상을 활용하는 게임 공간은 사용자에게 극대화된 현실감을 줄 수 있습니다.
FPS 게임은 높은 몰입감과 현실감이 중요한 게임 장르입니다.
구면 영상을 활용한 배경 공간은 현실감을 강조하는 FPS 게임에 적합한 기술입니다.
그러나, FPS 게임에 구면 영상을 배경으로 적용할 때에는 공간의 깊이 파악, 다양한 재질에 따른 역동적인 변화 등 고려해야 할 점들이 있습니다.

<div align="center">
  <img class="scalezoom_small" src="https://user-images.githubusercontent.com/32832618/124544942-19bedf00-de63-11eb-8eb8-381c5347d97c.png" height="200">
</div>

본 연구 프로그램은 구면 파노라마를 활용한 배경 공간을 배경으로 하는 FPS 게임에서 질감을 고려하여 역동적인 충돌 효과음을 생성하는 방법을 제안합니다.
제안 방법은 깊이맵을 통해 공간감을 형성하고, 총알의 충돌 지점 주변 재질을 분석하여 역동적인 충돌 효과음을 생성합니다.
제안 방법을 구면 공간을 사용하는 FPS 게임에 적용하여 실험한 결과 다양한 충돌 효과음을 효과적으로 생성됨을 보였습니다.

# 상세 설명
<div align="center">
  <img class="scalezoom_small" src="https://user-images.githubusercontent.com/32832618/124545133-6d312d00-de63-11eb-900f-6c9be7f20e88.png" height="200">
  <img class="scalezoom_small" src="https://user-images.githubusercontent.com/32832618/124545137-6e625a00-de63-11eb-98c5-35df2dba33fd.png" height="200">
</div>
 
설계한 시스템은 구면 파노라마 이미지를 기반으로 큐브맵 스카이박스를 생성합니다. 이는 증강현실 공간으로 활용됩니다.
시스템은 총알 충돌 지점의 주변 이미지 영역을 파악하여 재질을 분석하고, 사전에 입력된 재질 데이터와 비교하여 적절한 충돌 효과음을 생성합니다.
이를 위해서 총알 충돌 지점 주변의 이미지 패치를 획득하고, 사전에 입력된 재질 데이터와의 이진 특성값 CS-LBP를 분석합니다.
사전 입력된 재질 데이터의 CS-LBP는 히스토그램으로 나타낼 경우 각각 고유의 특성을 지니고 있습니다.
충돌 지점의 히스토그램과 사전 입력된 재질에 관한 히스토그램을 비교할 경우, 해당 지점에서 출력해야 할 충돌음을 파악할 수 있습니다.
더욱 자세한 내용은 하단의 버튼을 통해 확인하실 수 있습니다.

# spherical-fps
This is game system including sound generation technique using cs-lbp.


# If you want to compile this project
- Compile with visual studio 2017 in "Development Editor" + "Win64" mode.
