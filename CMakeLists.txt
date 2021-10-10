cmake_minimum_required(VERSION 3.16)
project(a10_Mitza23-1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "C:\\Qt\\5.15.2\\mingw81_64")
set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)


include_directories(Domain)
include_directories(Exceptions)
include_directories(Repository)
include_directories(Service)
include_directories(Tests)
include_directories(UI)
include_directories(Validator)

add_executable(a10_Mitza23-1
        Domain/DynamicArray.h
        Domain/Tutorial.cpp
        Domain/Tutorial.h
        Exceptions/Exception.h
        Exceptions/RepositoryException.h
        Exceptions/ServiceException.h
        Repository/Repository.cpp
        Repository/Repository.h
        Service/ServiceAdmin.cpp
        Service/ServiceAdmin.h
        Service/ServiceUser.cpp
        Service/ServiceUser.h
        Tests/testAll.cpp
        Tests/testRepo.cpp
        Tests/testRepo.h
        Tests/testServiceAdmin.cpp
        Tests/testServiceAdmin.h
        Tests/testServiceUser.cpp
        Tests/testServiceUser.h
        Tests/testTutorial.cpp
        Tests/testTutorial.h
        UI/UI.cpp
        UI/UI.h
        Validator/Validator.cpp
        Validator/Validator.h
        main.cpp
        Tests/testAll.h
        Repository/FileRepository.cpp
        Repository/FileRepository.h
        Exceptions/ValidatorException.h
        Tests/testFile.cpp
        Tests/testFile.h
        Repository/CSVRepository.cpp
        Repository/CSVRepository.h
        Repository/HTMLRepository.cpp
        Repository/HTMLRepository.h
        UI/RoleSelector.cpp
        UI/RoleSelector.h
        UI/Admin/AdminPanel.cpp
        UI/Admin/AdminPanel.h
        UI/Admin/AddAdmin.cpp
        UI/Admin/AddAdmin.h
        UI/Admin/DeleteAdmin.cpp
        UI/Admin/DeleteAdmin.h UI/Admin/UpdateAdmin.cpp UI/Admin/UpdateAdmin.h UI/User/UserPanel.cpp UI/User/UserPanel.h UI/User/FilterUser.cpp UI/User/FilterUser.h UI/User/DeleteUser.cpp UI/User/DeleteUser.h UI/User/DisplayUser.cpp UI/User/DisplayUser.h UI/FileOptions/FileOptions.cpp UI/FileOptions/FileOptions.h Domain/Commands/Command.h Service/UndoService.cpp Service/UndoService.h
        Service/IService.h Domain/Commands/Admin/AddCommandAdmin.cpp Domain/Commands/Admin/AddCommandAdmin.h Domain/Commands/Admin/DeleteCommandAdmin.cpp Domain/Commands/Admin/DeleteCommandAdmin.h Domain/Commands/Admin/UpdateTitleCommandAdmin.cpp Domain/Commands/Admin/UpdateTitleCommandAdmin.h Domain/Commands/Admin/UpdatePresenterCommandAdmin.cpp Domain/Commands/Admin/UpdatePresenterCommandAdmin.h Domain/Commands/User/AddCommandUser.cpp Domain/Commands/User/AddCommandUser.h Domain/Commands/User/DeleteCommandUser.cpp Domain/Commands/User/DeleteCommandUser.h UI/User/TutorialModel.cpp UI/User/TutorialModel.h)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})