# multi_car_simultion

**``OpenGL2.0``으로 제작되었습니다.**

## Demo

- 데모 영상에서 사용자의 자동차는 가운데 도로에서 아래에서 위로 직진하는 옅은 겨자색 이다.
<img src="./multi_car_simulation.gif" width="600">

### Contents

- 자동차 시뮬레이션 및 자동차 운전 점수 측정
- 출발지 부터 도착지 (파란 큐브로 표시) 까지 주행 시뮬레이션
- 다른 자동차들과의 충돌 , 신호 위반 등을 측정하여 점수 계산
- ``A``, ``D`` , ``W``, ``S`` 키를 통해 회전, 직진 및 후진 조절
- ``P`` 키를 통해 시점을 맵 기준 시점, 사용자의 차 기준 시점으로 변환이 가능하다.
- 사용 기술 : ``OpenGL``, ``C++``

## file tree

```bash
└─car_simulator
    ├─main.cpp
    ├─map.cpp
    ├─traffic_sign.cpp
    ├─user_car.cpp
    ├─car.cpp
    ├─basic_setting.cpp
    ├─map.h
    ├─traffic_sign.h
    ├─user_car.h
    ├─car.h
    └─basic_setting.h
```

## To Do
***

- [x] ~~나무 오브젝트 생성~~
- [x] ~~키보드 키를 통한 시점 변화~~
- [ ] 감점 요소 추가

