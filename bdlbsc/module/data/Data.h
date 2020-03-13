//
// Created by dev on 2020/3/12.
//

#ifndef MODULES_DATA_H
#define MODULES_DATA_H

#include <bdlbsc/module/data/DataDb.h>
#include <bdlbsc/module/supper/IData.h>

#include <cpp_redis/cpp_redis>


namespace bdlbsc
{
    class Data : public IData
    {

        Q_OBJECT
    public:
        Data();
        ~Data();

        void set_app_id(QString values) override;
        QString get_app_id() override;
        void set_app_secret(QString values) override;
        QString get_app_secret() override;
        void set_app_access_token(QString values) override;
        QString get_app_access_token() override;
        void set_user_access_token(QString values) override;
        QString get_user_access_token() override;
        void set_user_id(QString values) override;
        QString get_user_id() override;

        QString get_base_url() override;
        void set_base_url(QString values) override;

    private:
        cpp_redis::client redis_client;

        QString _app_id;
        QString _app_secret;
        QString _app_access_token;
        QString _user_access_token;
        QString _user_id;
        QString _base_url;
    };

} // namespace bdlbsc

#endif //MODULES_DATA_H
