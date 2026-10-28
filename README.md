# 机械臂视觉分拣

基于 STM32、OpenMV 和总线舵机的机械臂视觉分拣项目。

## 项目结构

```text
.
├── firmware/                    # 从机械臂v1.5.zip 整理的 STM32 工程
│   ├── App/                     # 机械臂动作接口及早期动作实现
│   ├── Bsp/                     # 总线舵机驱动、OpenMV 串口接收
│   ├── Core/                    # 主程序、中断与外设初始化
│   ├── Drivers/                 # 原工程附带的 STM32 HAL / CMSIS
│   ├── System/delay/            # 延时模块
│   ├── MDK-ARM/                 # Keil 工程与启动文件
│   └── 4.3.2.ioc                # STM32CubeMX 工程配置
├── hardware/                    # 机械臂 STEP 结构模型
└── docs/                        # 公开版技术文档与文件校验清单
```

## 资料入口

- [STM32 固件工程](firmware/MDK-ARM/4.3.2.uvprojx)
- [主控制流程](firmware/Core/Src/main.c)
- [OpenMV 通信接收](firmware/Bsp/openmv.c)
- [总线舵机驱动](firmware/Bsp/bus_servo.c)
- [赛事技术文档](docs/AIC-2025-98061736技术文档--公开版.docx)
- [机械臂结构拓扑优化模型](hardware/AIC-2025-98061736机械臂结构拓扑优化方案.STEP)
- [原始资料及源码 SHA-256 校验清单](docs/source-manifest.json)

## 系统组成

OpenMV 提供视觉检测数据，STM32 通过串口接收数据、选择抓取和放置动作，再向总线舵机发送位置与运动时间指令。机械结构与轻量化设计见技术文档和 STEP 模型。

```mermaid
flowchart LR
    A[OpenMV 视觉模块] -->|USART3 接收检测数据| B[STM32F103RC]
    B -->|USART2 发送位置与时间指令| C[总线舵机]
    C --> D[机械臂与夹爪]
```

当前固件的动作入口位于 `Core/Src/main.c`，包含抓取动作、按检测结果选择放置位置及三轮执行流程。舵机位置、动作时间和颜色映射沿用原始程序，复现时需结合实际装配核对。

