﻿# 背景

随着国产微控制器的崛起，市场上的微控制器种类越来越多。然而，以前的微控制器开发往往忽略了整体框架和程序分层，导致更换微控制器型号往往需要更改应用层代码，这使得开发工作变得繁重且乏味。常见的开发方式大多分为两种:
常见的开发方式通常分为两种：裸机编程和RTOS编程，由于两种方式的代码编写方式存在巨大差异，因此在两种方式之间切换意味着需要进行大规模的工程修改。
**mr-library** 的目标是帮助开发者提高开发效率和代码通用性，降低平台迁移的难度。

 ----------

# mr-library 简介

**mr-library** 是一个嵌入式软件库，完全采用C语言编写，使用面向对象的设计方法，代码框架清晰，可以快速移植到不同的平台。它包括以下部分：

* 内核层: **mr-library** 的核心部分，包含容器、对象、管理器等。将各种对象注册到内核维护的容器中，使得应用更加高效有序。
* 设备框架层: 提供统一的设备接口，将不同的设备接入到内核中。在应用层，仅需调用内核设备I/O接口即可访问设备。
* 硬件驱动层: 为设备框架层设备提供必要的驱动，当硬件更换时仅修改驱动层。
* 组件层: 通过内核提供的API实现不同的功能。包括但不限于虚拟文件系统、通用传感器模块、网络框架等。
* 软件包: 可独立使用，无依赖的软件包。

 ----------

# 代码目录

**mr-library** 的代码目录结构如下表所示：

| 名称       | 描述    |
|:---------|:------|
| bsp      | 板级支持包 |
| device   | 设备文件  |
| document | 文档    |
| driver   | 驱动文件  |
| include  | 库头文件  |
| module   | 组件    |
| package  | 软件包   |
| src      | 库源文件  |

 ----------

# 许可协议

遵循 **Apache License 2.0** 开源许可协议，可免费应用于商业产品，无需公开私有代码。

 ----------

# 贡献代码

如果您对 **mr-library** 项目感兴趣，欢迎参与开发并成为代码贡献者。欢迎加入讨论群 **199915649(QQ)** 分享您的观点。